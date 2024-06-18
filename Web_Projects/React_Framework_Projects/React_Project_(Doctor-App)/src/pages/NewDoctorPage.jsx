import {Button, Input, Textarea} from "@nextui-org/react";
import axios from "axios";
import {useState} from "react";
import {Link} from "react-router-dom";

const NewDoctorPage = () => {

    const initialState = {
        name : "",
        phone : "",
        specialization : "",
        info : "",
    }
    const [state, setState] = useState(initialState)
    const [loading, setLoading] = useState(false)

    const handleChange = (v, name) => {
        setState((prev) => ({...prev, [name]: v.target.value}))
    }

    const onSave = () => {
        setLoading(true)
        axios.post("/api/doctors",state,{
            headers: {
                "Content-Type": "application/json"
            }
        })
            .then((r) => {
                alert("successfully Added")
                setState(initialState)
            })
            .catch((error) => {})
            .finally(() => {
                setLoading(false)
            })
    }

    return (
        <>
            <h1 className="text-center text-5xl mb-20 mt-10">New Doctor</h1>
            <div className="flex justify-center">
                <div className="w-1/2">
                    <Input value={state.name} onChange={(e) => handleChange(e,"name")} className="mb-3" label="doctor name" color="primary" variant="bordered" placeholder="enter doctor name" />
                    <Input value={state.phone} onChange={(e) => handleChange(e,"phone")} className="mb-3" label="phone number" color="primary" variant="bordered" placeholder="enter doctor phone number" />
                    <Input value={state.specialization} onChange={(e) => handleChange(e,"specialization")} className="mb-3" label="specialization" color="primary" variant="bordered" placeholder="enter doctor specialization" />
                    <Textarea value={state.info} onChange={(e) => handleChange(e,"info")} className="mb-10" label="more info" minRows={10} variant="bordered" color="primary" />
                    <Button className="mb-10" disabled={loading} onClick={onSave} fullWidth color="success">Save</Button>
                    <Link to="/" className="border rounded-2xl p-3" >Go back</Link>
                </div>
            </div>
        </>
    );
};

export default NewDoctorPage;