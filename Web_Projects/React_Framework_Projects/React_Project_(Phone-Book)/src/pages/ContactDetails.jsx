import {Link, useParams} from "react-router-dom";
import {useEffect, useState} from "react";
import axios from "axios";
import Loading from "../components/Loading.jsx";
import LabeledText from "../components/LabeledText.jsx";
import {FontAwesomeIcon} from "@fortawesome/react-fontawesome";
import { faArrowLeft } from "@fortawesome/free-solid-svg-icons";

const ContactDetails = () => {
    const {contactId} = useParams();
    const [data, setData] = useState();
    const [loading, setLoading] = useState(true);

    useEffect(() => {
        getDetails();
    }, []);

    const getDetails = () => {
        setLoading(true);
        axios.get(`/api/contacts/${contactId}`)
            .then((r) => {
                setData(r.data)
            })
            .catch((e) => {})
            .finally(() => {
                setLoading(false)
            })
    }

    if (loading) {
        return <Loading />
    }

    return (
        <>
            <Link className="text-white" to="/" ><FontAwesomeIcon fontSize={30} icon={faArrowLeft} /></Link>
            <div className="p-10">
                <LabeledText label="Name" text={data.name} />
                <LabeledText label="Phone" text={data.phone} />
                <LabeledText label="Email" text={data.email} />
                <hr className="my-5 mx-20"/>
                <LabeledText valueSize="text-2xl" label="Notes:" text={data.notes} />
            </div>
        </>
    );
};

export default ContactDetails;