import {Link} from "react-router-dom";
import {FontAwesomeIcon} from "@fortawesome/react-fontawesome";
import {faEye, faTrash} from "@fortawesome/free-solid-svg-icons";
import axios from "axios";
import {useState} from "react";
import {Spinner} from "@nextui-org/react";

const ContactTile = ({contact, onContactDeleted}) => {
    const [loading, setLoading] = useState(false)
    const deleteContact = () => {
        setLoading(true)
        axios.delete(`/api/contacts/${contact.id}`)
            .then((r) => {
                if (onContactDeleted) {
                    onContactDeleted();
                }
            })
            .catch((e) => {})
            .finally(() => {
                setLoading(false)
            })
    }
    return (
        <div className="bg-black bg-opacity-25 text-white flex justify-between p-5 rounded-full">
            <div className="flex flex-wrap gap-10 items-center">
                <h4 className="pl-5 text-large font-semibold">{contact.name}</h4>
                <p className="font-light">{contact.phone}</p>
            </div>
            <div className="pr-2">
                <span className="mx-5">
                    {
                        loading ? <Spinner /> : <FontAwesomeIcon onClick={deleteContact} className="cursor-pointer transition-colors duration-700 hover:text-red-800 text-red-600" color="danger" fontSize={20} icon={faTrash}/>
                    }
                </span>
                <Link className="transition-colors duration-700 hover:text-blue-500"
                      to={`/contacts/${contact.id}/details`}>
                    <FontAwesomeIcon fontSize={20} icon={faEye}/>
                </Link>
            </div>
        </div>
    );
};

export default ContactTile;